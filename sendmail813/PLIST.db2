@comment $NetBSD: PLIST.db2,v 1.1 2004/08/18 14:33:41 adrian_p Exp $
@exec ${MV} -f /usr/sbin/makemap /usr/sbin/makemap.8.8 || ${TRUE}
@unexec ${MV} -f /usr/sbin/makemap.8.8 /usr/sbin/makemap || ${TRUE}
