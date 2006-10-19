# $NetBSD: Makefile,v 1.1.1.1 2006/10/19 05:46:29 kcf Exp $
#

XSPDVERSION=		6.3.1
DISTNAME=		xspsrc_051219_tar
PKGNAME=		xspd-${XSPDVERSION}
CATEGORIES=		www
MASTER_SITES=		http://home.arcor.de/joachimschulze/xsp/download/
EXTRACT_SUFX=		.tgz
MAINTAINER=		kcf@users.sourceforge.net
HOMEPAGE=		http://home.arcor.de/joachimschulze/xsp/
COMMENT=		http server using C/C++/JAVA/Shell xsp based pages
WRKSRC=			${WRKDIR}
MAKEFILE=		xspdinstall
USE_TOOLS+=		tar mkdir echo make
MAKE_ENV+=		XSPSYS_TAR="xspsys_051219.tar"
MAKE_ENV+=		XSPAPP_TAR="xspapp_051219.tar"
MAKE_ENV+=		XSPSYSDOC_TAR="xspsysdoc_051219.tar"
#WRKSRC=		Readme.html Readme.txt xspapp_051219.tar xspdinstall xspjava_051219.tar xspjsys_051219.tar xspjsysdoc_051219.tar xspsys_051219.tar xspsysdoc_051219.tar


.include "../../mk/bsd.pkg.mk"
