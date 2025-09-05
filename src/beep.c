/*
 *
 *
 * Filename : beep.c
 *
 * Author   : Simon J Raybould.
 *
 * Date     : Friday 23rd August 1991.
 *
 * Desc     : Produce a audiable sound.
 *
 * Copyright (c) 1991-1993 Simon J Raybould
 *
 * SPDX-License-Identifier: BSD-2-Clause
 *
 *
 * Revision History
 * ================
 *
 * $Log: beep.c,v $
 * Revision 1.3  1993/05/17  23:33:10  sie
 * Underscores added to names.
 * Changes for version 2.10
 *
 * Revision 1.2  1992/06/10  23:44:19  sie
 * Added serial support.
 *
 * Revision 1.1  91/09/07  11:39:58  sie
 * Initial revision
 * 
 *
 */

static char *rcsid = "$Header: /SRC/lib/curses/src/RCS/beep.c,v 1.3 1993/05/17 23:33:10 sie Exp $";

#include <fcntl.h>
#include "acurses.h"

beep(void)
{
  struct IOAudio *AIOptr;
  struct MsgPort *port;
  UBYTE whichannel[] = { 1, 2, 4, 8 };
  ULONG device;
  BYTE *sound_data;

  if(!(_CursesFlags & CFLAG_INITSCR))  /* Haven't called initscr() */
    return ERR;
  
  if(_CursesType == CUST_CURSES) {
    AIOptr = (struct IOAudio *) AllocMem(sizeof(struct IOAudio), MEMF_CHIP|MEMF_PUBLIC);
    if(!AIOptr)
      _CleanExit(1);
    
    port = (struct MsgPort *)CreatePort(0, 0);
    if(!port) {
      FreeMem((APTR)AIOptr, sizeof(struct IOAudio));
      return ERR;
    }
    
    AIOptr->ioa_Request.io_Message.mn_ReplyPort = port;
    AIOptr->ioa_Request.io_Message.mn_Node.ln_Pri = 0;
    AIOptr->ioa_Request.io_Command = ADCMD_ALLOCATE;
    AIOptr->ioa_Request.io_Flags = ADIOF_NOWAIT;
    AIOptr->ioa_AllocKey = 0;
    AIOptr->ioa_Data = whichannel;
    AIOptr->ioa_Length = sizeof(whichannel);
    
    device = OpenDevice("audio.device", 0L, (struct IORequest *)AIOptr, 0L);
    if(device) {
      printf("Curses beep() - Can't open Audio Device\n");
      FreeMem((APTR)AIOptr, sizeof(struct IOAudio));
      return ERR;
    }
    
    sound_data = (BYTE *) AllocMem(SOUNDLENGTH, MEMF_CHIP|MEMF_PUBLIC);
    if(!sound_data) {
      FreeMem((APTR)AIOptr, sizeof(struct IOAudio));
      return ERR;
    }
    
    sound_data[0]=127;
    sound_data[1]=-127;
    
    AIOptr->ioa_Request.io_Message.mn_ReplyPort = port;
    AIOptr->ioa_Request.io_Command = CMD_WRITE;
    AIOptr->ioa_Request.io_Flags = ADIOF_PERVOL;
    AIOptr->ioa_Data = (UBYTE *)sound_data;
    AIOptr->ioa_Cycles = 200;
    AIOptr->ioa_Length = SOUNDLENGTH;
    AIOptr->ioa_Period = 2000;
    AIOptr->ioa_Volume = 64;
    
    BeginIO((struct IORequest *)AIOptr);
    WaitIO((struct IORequest *)AIOptr);
    
    FreeMem((APTR)sound_data, SOUNDLENGTH);
    DeletePort(port);
    CloseDevice((struct IORequest *)AIOptr);
    FreeMem((APTR)AIOptr, sizeof(struct IOAudio));
  } else
    fputc(BELL, stdout);
}
