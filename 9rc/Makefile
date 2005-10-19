# $NetBSD: Makefile,v 1.5 2005/10/19 11:14:25 leonardschmidt Exp $
#

DISTNAME=	9rc-20051017
CATEGORIES=	shells
MASTER_SITES=	http://wmi.modprobe.de/snaps/

MAINTAINER=	lems@gmx.net
HOMEPAGE=	http://wmi.modprobe.de/
COMMENT=	Port of various original plan9 tools

CONFLICTS=		rc-[0-9]*

USE_PKGINSTALL=		yes
PKG_SHELL=		bin/rc

.include "../../mk/bsd.prefs.mk"

.if ${GNU_PROGRAM_PREFIX} == ""
CONFLICTS+=		grep-[0-9]*
CONFLICTS+=		coreutils-[0-9]*
.endif

.include "../../mk/bsd.pkg.mk"
