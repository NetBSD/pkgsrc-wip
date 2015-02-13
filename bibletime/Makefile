# $NetBSD: Makefile,v 1.4 2015/02/13 15:18:00 nros Exp $

DISTNAME=		bibletime-2.10.1
PKGREVISION=		2
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=bibletime/}
EXTRACT_SUFX=		.tar.xz
EXTRACT_USING=		bsdtar

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://bibletime.info/
COMMENT=		Bible study program based on SWORD and QT
LICENSE=		gnu-gpl-v2

USE_CMAKE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config

SUBST_CLASSES+=		prefix
SUBST_FILES.prefix=	${WRKSRC}/cmake/docs/*.xsl
SUBST_STAGE.prefix=	post-patch
SUBST_SED.prefix=	-e 's,@PREFIX@,${PREFIX},g'

DEPENDS+=	dejavu-ttf-[0-9]*:../../fonts/dejavu-ttf

.include "options.mk"

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/libclucene/buildlink3.mk"
.include "../../wip/sword/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
