# $NetBSD$

DISTNAME=	tfschema-0.7.9
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=minamijoyo/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/minamijoyo/tfschema
COMMENT=	Schema inspector for Terraform / OpenTofu providers
LICENSE=	mit

SUBST_CLASSES+=			providers-prefix
SUBST_STAGE.providers-prefix=	pre-configure
SUBST_MESSAGE.providers-prefix=	Honor providers installed via pkgsrc
SUBST_FILES.providers-prefix=	tfschema/client.go
SUBST_VARS.providers-prefix=	PREFIX

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
