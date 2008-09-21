# $NetBSD: Makefile,v 1.1.1.1 2008/09/21 20:02:12 pettai Exp $
#

DISTNAME=	just-0.3.6
CATEGORIES=	net tcl tk
MASTER_SITES=	ftp://hamster.urc.uninett.no/pub/unix/network/snmp/scotty/

MAINTAINER=	pettai@nordu.net
COMMENT=	Jarle's useless SNMP tools

DEPENDS+=	tk>=8.3.2:../../x11/tk
DEPENDS+=	tcl-scotty>=2.1.10:../../net/tcl-scotty

.include "../../mk/bsd.prefs.mk"

GNU_CONFIGURE=  yes
CONFIGURE_ARGS+= --with-tcl-config=${PREFIX}/lib

TNMVER!= ${ECHO} 'puts $$tnm(version); exit' | scotty
PLIST_SUBST+= TNMVER=${TNMVER}

.include "../../mk/bsd.pkg.mk"
