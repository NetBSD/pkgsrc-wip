# $NetBSD: Makefile,v 1.2 2015/04/17 22:25:04 jgoamakf Exp $

DISTNAME=	custom_printf-112.24.00
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=janestreet/}
GITHUB_PROJECT=	custom_printf
GITHUB_TAG=	112.24.00
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/custom_printf/
COMMENT=	Syntax extension for printf format strings
LICENSE=	apache-2.0

OCAML_USE_OASIS=	yes

.include "../../devel/ocaml-type_conv/buildlink3.mk"
.include "../../devel/ocaml-sexplib/buildlink3.mk"
.include "../../wip/ocaml-pa_ounit/buildlink3.mk"
.include "../../lang/camlp4/buildlink3.mk"
.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
