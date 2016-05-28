# $NetBSD: Makefile,v 1.3 2012/10/01 21:43:26 asau Exp $
#

DISTNAME=	just-0.3.6
CATEGORIES=	net tcl tk
MASTER_SITES=	ftp://hamster.urc.uninett.no/pub/unix/network/snmp/scotty/

MAINTAINER=	pettai@nordu.net
COMMENT=	Jarle's useless SNMP tools

DEPENDS+=	tk>=8.3.2:../../x11/tk
DEPENDS+=	tcl-scotty>=2.1.10:../../net/tcl-scotty


.include "../../mk/bsd.prefs.mk"

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-tcl-config=${PREFIX}/lib

TNMVER_CMD=	${ECHO} 'puts $$tnm(version); exit' | ${PREFIX}/bin/scotty
PLIST_SUBST+=	TNMVER=${:!${TNMVER_CMD}!}

.include "../../mk/bsd.pkg.mk"
