# $NetBSD: Makefile,v 1.2 2009/08/07 18:24:16 jihbed Exp $
#

DISTNAME=	lisaac-0.13.1
CATEGORIES=	lang
MASTER_SITES=	http://isaacproject.u-strasbg.fr/download/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://isaacproject.u-strasbg.fr/li.html
COMMENT=	Lisaac is the first compiled POO based on prototype concepts
#LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gmake
USE_LANGUAGES=  c c++

ONLY_FOR_COMPILER=	gcc
ONLY_FOR_PLATFORM= NetBSD-*-i386 Linux-*-i386

PLIST_SRC+=	PLIST
PLIST_SRC+=	${PKGDIR}/PLIST.doc ${PKGDIR}/PLIST.li

INSTALLATION_DIRS+=	bin


.include "../../mk/bsd.pkg.mk"
