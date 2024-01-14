$NetBSD: patch-src_zm__rtp__ctrl.h,v 1.1 2020/07/12 16:58:42 gdt Exp $

Work around:
  zm_rtp_ctrl.h:128:31: error: flexible array member 'RtpCtrlThread::RtcpPacket::<unnamed union>::Bye::srcN' in an otherwise empty 'struct RtpCtrlThread::RtcpPacket::<unnamed union>::Bye'

Not reported upstream because pkgsrc is out of date; to be done if this is not resolved by updating.

