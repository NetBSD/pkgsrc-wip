# $NetBSD: Makefile,v 1.3 2015/07/12 00:35:40 thomasklausner Exp $

DISTNAME=	xtrkcad-source-5.3.1GA
PKGNAME=	${DISTNAME:C/source-//}
CATEGORIES=	cad
MASTER_SITES=	http://sourceforge.net/projects/xtrkcad-fork/files/XTrackCad/Version%205.3.1/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.xtrkcad.org/
COMMENT=	CAD program for designing model railroads
LICENSE=	apache-2.0

TOOL_DEPENDS+=	librsvg>=2.60.2:../../graphics/librsvg

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

.include "../../mk/bsd.prefs.mk"
PLIST_SRC=  PLIST.common
.if ${OPSYS} == "Darwin"
PLIST_SRC+= ${.CURDIR}/PLIST.darwin
.else
PLIST_SRC+= ${.CURDIR}/PLIST.others
.endif

.include "../../devel/cmake/build.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../archivers/libzip/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
