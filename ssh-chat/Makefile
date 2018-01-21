# $NetBSD$

GITHUB_TAG=	v1.7
DISTNAME=	${GITHUB_TAG}
DIST_SUBDIR=	ssh-chat
PKGNAME=	${DIST_SUBDIR}-${GITHUB_TAG:S/v//}
CATEGORIES=	chat security
MASTER_SITES=	${MASTER_SITE_GITHUB:=shazow/}
GITHUB_PROJECT=	ssh-chat

MAINTAINER=	alnsn@yandex.ru
HOMEPAGE=	https://github.com/shazow/ssh-chat
COMMENT=	Chat over SSH
LICENSE=	mit

REPLACE_BASH+=	build_release

WRKSRC=		${WRKDIR}
GO_DIST_BASE=	ssh-chat-${GITHUB_TAG:S/v//}
GO_SRCPATH=	github.com/shazow/ssh-chat

.include "../../lang/go/go-package.mk"
.include "../../security/go-crypto/buildlink3.mk"
.include "../../wip/go-flags/buildlink3.mk"
.include "../../wip/go-humanize/buildlink3.mk"
.include "../../wip/go-log/buildlink3.mk"
.include "../../wip/go-pass/buildlink3.mk"
.include "../../wip/go-rateio/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
