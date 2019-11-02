# $NetBSD: Makefile,v 1.20 2019/08/27 19:56:03 schmonz Exp $

GITHUB_PROJECT=	ptmap
DISTNAME=	ptmap-2.0.4
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=backtracking/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ocaml-community/sedlex
COMMENT=	Implementation of maps over integers implemented as Patricia trees
LICENSE=	gnu-lgpl-v2.1

BUILD_DEPENDS+=	ocaml-obuild-[0-9]*:../../wip/ocaml-obuild

.include "../../devel/ocamlbuild/buildlink3.mk"
.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
