# $NetBSD: Makefile,v 1.1.1.1 2003/11/06 05:41:33 mpasternak Exp $

DISTNAME=	chprofessional-4.0.0.linux2.2.5.intel
PKGNAME=	linux-chproffessional-4.0.0
CATEGORIES=	devel
MASTER_SITES=	http://www.softintegration.com/download/software/release/Linux/

MAINTAINER=	dotz@irc.pl
HOMEPAGE=	http://www.softintegration.com/products/chprofessional/
COMMENT=	Ch is an interactive C development environment

NO_BUILD=	# defined

#
# I have included chpro-license for pkgsrc-wip purposes as
# linux-chprofessional/licenses/chpro-license. Basically, 
# this tool is free for academic purposes *only*. For personal
# or commercial use, go for Ch standard edition
#

LICENSE=	chpro-license

#
# Webpage claims, that there are ports for Solaris, HP-UX, MacOS
# and Windows. Unfortunatley, I can't test on those, so until someone
# does this... :
# 

ONLY_FOR_PLATFORM=	*-i386

do-install:
	cd ${WRKSRC} && ./install.sh

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
DEPENDS+=	suse_compat-[0-9]*:../../emulators/${SUSE_DIR_PREFIX}_compat
DEPENDS+=	suse_x11-[0-9]*:../../emulators/${SUSE_DIR_PREFIX}_x11
.endif

.include "../../mk/bsd.pkg.mk"
