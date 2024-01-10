# $NetBSD$

DISTNAME=	gptfdisk-1.0.9
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gptfdisk/1.0.9/}
# EXTRACT_SUFX=	.tar.gz

MAINTAINER=		greg-org-netbsd@akua.com
HOMEPAGE=		https://www.rodsbooks.com/gdisk/
COMMENT=		The standard in gpt partition editing
LICENSE=		gnu-gpl-v2

# GNU_CONFIGURE=		no
# HAS_CONFIGURE=		no
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake

INSTALLATION_DIRS=	sbin ${PREFIX}/${PKGMANDIR}

SBIN_FILES+=	gdisk cgdisk sgdisk fixparts
MAN_FILES+=	gdisk.8 cgdisk.8 sgdisk.8 fixparts.8

MAKE_PROGRAM=	gmake

do-install:
.for f in ${SBIN_FILES}
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/sbin/${f}
.endfor
.for f in ${MAN_FILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/${PKGMANDIR}/${f}
.endfor

.include "../../devel/libuuid/buildlink3.mk"
.include "../../devel/ncursesw/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
