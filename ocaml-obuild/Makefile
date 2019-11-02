# $NetBSD$

GITHUB_PROJECT=	obuild
DISTNAME=	obuild-0.1.10
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ocaml-obuild/}
GITHUB_TAG=	obuild-v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ocaml-obuild/obuild/
COMMENT=	Simple package build system for ocaml
LICENSE=	2-clause-bsd

USE_TOOLS+=	bash

do-build:	bootstrap-obuild
.PHONY:		bootstrap-obuild

bootstrap-obuild:
	cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${BASH} bootstrap

OCAML_USE_DUNE=	yes

.include "../../lang/ocaml/buildlink3.mk"
.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
