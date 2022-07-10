# $NetBSD: Makefile,v 1.18 2022/04/18 19:10:32 adam Exp $

DISTNAME=	telegram-purple_1.4.7.orig
PKGNAME=	telegram-purple-1.4.7
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=majn/}
GITHUB_PROJECT=	telegram-purple
GITHUB_RELEASE=	v1.4.7

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/majn/telegram-purple/
COMMENT=	libpurple protocol plugin for the Telegram messenger
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/${PKGBASE}
USE_TOOLS+=	gmake msgfmt pkg-config

GNU_CONFIGURE=	yes

BUILDLINK_TRANSFORM+=	rm:-Werror

.include "../../chat/libpurple/buildlink3.mk"
.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
