# $NetBSD$

GITHUB_PROJECT=	ic
GITHUB_TAG=	3fcfb21b6cf78b23a47c35b745aeda445c6834d9
DISTNAME=	${GITHUB_PROJECT}
PKGNAME=	${GITHUB_PROJECT}-${GITHUB_TAG}
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=unix4fun/}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/unix4fun/ic/
COMMENT=	IC4F (Irc Crypto 4 Fun) simple IRC encryption mechanism
LICENSE=	modified-bsd

DEPENDS+=	weechat-[0-9]*:../../chat/weechat

GO_DEPS=	github.com/nu7hatch/gouuid:179d4d0c4d8d407a32af483c2354df1d2c91e6c3
GO_SRCPATH=	github.com/unix4fun/ic
GO_DIST_BASE=	${PKGNAME}

CHECK_RELRO_SKIP+=	bin/ic

do-install:
	${RUN} cd ${WRKDIR} && ${PAX} -rw bin/ic ${DESTDIR}${PREFIX}

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.prefs.mk"

.include "../../devel/go-protobuf/buildlink3.mk"
.include "../../security/go-crypto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
