# $NetBSD: Makefile,v 1.1.1.1 2010/01/13 11:16:50 obache Exp $
#

DISTNAME=	zinnia-tomoe-0.6.0-20080911
PKGNAME=	zinnia-tomoe-0.6.0.20080911
CATEGORIES=	wip
MASTER_SITES=	http://downloads.sourceforge.net/project/zinnia/zinnia-tomoe/0.6.0-20080911/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://zinnia.sourceforge.net/
COMMENT=	Zinna recognition models traned with Tomoe data
#LICENSE=	# Tomoe's

BUILD_DEPENDS+=	zinnia-[0-9]*:../../wip/zinnia

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LANGUAGES=	# none

FIND_PREFIX:=	ZINNIA_DIR=zinnia
.include "../../mk/find-prefix.mk"

CONFIGURE_ARGS+=	--with-zinnia-convert=${ZINNIA_DIR}/bin/zinnia_convert

.include "../../wip/zinnia/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
