# $NetBSD: Makefile,v 1.1 2024/02/25 22:00:09 wiz Exp $

COMMITS=	144
DISTNAME=	yasr-0.0.0.${COMMITS}
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=mgorse/}
GITHUB_TAG=	f60db19350542e6f4b7d268a310b9f2b9f3076c0

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mgorse/yasr
COMMENT=	Lightweight and portable screen reader
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c
USE_TOOLS=	pkg-config msgfmt xgettext

.include "../../devel/meson/build.mk"
.include "../../audio/speech-dispatcher/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
