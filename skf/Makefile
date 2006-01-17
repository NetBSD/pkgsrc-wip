# $NetBSD: Makefile,v 1.1.1.1 2006/01/17 04:53:58 obache Exp $

PKGNAME=	skf-1.93.9
DISTNAME=	skf_1.93.9
CATEGORIES=	japanese converters
MASTER_SITES=	http://downloads.sourceforge.jp/skf/17934/

MAINTAINER=	obata@lins.jp
HOMEPAGE=	http://sourceforge.jp/projects/skf/
COMMENT=	Simple Kanji Filter - i18n kanji converter

WRKSRC=		${WRKDIR}/skf-1.93
INSTALL_TARGET=	install locale_install

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=  yes
MANCOMPRESSED=	yes

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
