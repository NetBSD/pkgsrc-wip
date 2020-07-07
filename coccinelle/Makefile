# $NetBSD: Makefile,v 1.29 2016/12/30 11:16:58 jaapb Exp $

DISTNAME=	coccinelle-1.0.8
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=coccinelle/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://coccinelle.lip6.fr/
COMMENT=	Tool for writing and applying semantic patches
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	ocaml-findlib-[0-9]*:../../devel/ocaml-findlib

DEPENDS+=	menhir>=20071212:../../devel/menhir

CONFIGURE_ARGS+=	--with-menhir
CONFIGURE_ARGS+=	--disable-pyml
CONFIGURE_ARGS+=	--with-python=${PYTHONBIN}

MAKE_JOBS_SAFE=		no

GNU_CONFIGURE=	yes
USE_TOOLS+=	aclocal autoconf automake gmake pkg-config

REPLACE_PYTHON=	tools/pycocci

TEST_TARGET=	check

pre-configure:
	cd ${WRKSRC} && ${SH} ./autogen

.include "../../lang/python/tool.mk"

.include "../../mk/dlopen.buildlink3.mk"

BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:M*}

.include "../../devel/pcre-ocaml/buildlink3.mk"
BUILDLINK_API_DEPENDS.ocaml+=	ocaml>=3.11
.include "../../lang/ocaml/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
