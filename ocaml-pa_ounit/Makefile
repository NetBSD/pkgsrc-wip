# $NetBSD: Makefile,v 1.5 2015/04/17 22:28:58 jgoamakf Exp $

DISTNAME=	pa_ounit-112.24.00
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=janestreet/}
GITHUB_PROJECT=	pa_ounit
GITHUB_TAG=	112.24.00
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/pa_ounit/
COMMENT=	OCaml inline testing
LICENSE=	apache-2.0

OCAML_USE_OASIS=	yes

.include "../../wip/ocaml-ounit/buildlink3.mk"
.include "../../lang/camlp4/buildlink3.mk"
.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
