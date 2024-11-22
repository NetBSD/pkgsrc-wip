# $NetBSD: Makefile,v 1.16 2021/01/27 13:35:58 leot Exp $

.include "../../wip/terraform/version.mk"

DISTNAME=	opentofu-${OPENTOFU_VERSION}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=opentofu/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://opentofu.org/
COMMENT=	Open source infrastructure as code
LICENSE=	mpl-2.0

SUBST_CLASSES+=			providers-prefix
SUBST_STAGE.providers-prefix=	pre-configure
SUBST_MESSAGE.providers-prefix=	Honor providers installed via pkgsrc
SUBST_FILES.providers-prefix=	cmd/tofu/provider_source.go
SUBST_VARS.providers-prefix=	PREFIX

# Do not install auxiliary programs
post-install:
	${RM} ${DESTDIR}${PREFIX}/bin/loggraphdiff
	${RM} ${DESTDIR}${PREFIX}/bin/main
	${RM} ${DESTDIR}${PREFIX}/bin/protobuf-compile

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
