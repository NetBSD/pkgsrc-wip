# $NetBSD: Makefile,v 1.29 2016/12/30 11:16:58 jaapb Exp $

DISTNAME=	coccinelle-1.0.6
CATEGORIES=	devel
MASTER_SITES=	http://coccinelle.lip6.fr/distrib/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://coccinelle.lip6.fr/
COMMENT=	Tool for writing and applying semantic patches
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	ocaml-findlib-[0-9]*:../../devel/ocaml-findlib

DEPENDS+=	menhir>=20071212:../../devel/menhir

CONFIGURE_ARGS+=	--with-menhir
CONFIGURE_ARGS+=	--disable-pyml

MAKE_JOBS_SAFE=		no

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake pkg-config
BUILD_TARGET=	all all.opt

REPLACE_PYTHON=	tools/pycocci

SUBST_CLASSES+=		man
SUBST_FILES.man+=	configure
SUBST_SED.man+=		-e "s,$${prefix}/man,$${prefix}/${PKGMANDIR},g"
SUBST_STAGE.man=	pre-configure
SUBST_MESSAGE.man=	Fixing manpath.

SUBST_CLASSES+=		python
SUBST_FILES.python+=	bundles/pyml/pyml-current/py.ml
SUBST_VARS.python+=	PYVERSSUFFIX
SUBST_STAGE.python=	pre-configure
SUBST_MESSAGE.python=	Fixing python command invokation.

TEST_TARGET=	test

.include "../../lang/python/tool.mk"

.include "../../mk/dlopen.buildlink3.mk"

BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:M*}

.include "../../devel/pcre-ocaml/buildlink3.mk"
BUILDLINK_API_DEPENDS.ocaml+=	ocaml>=3.11
.include "../../lang/ocaml/buildlink3.mk"
.include "../../lang/camlp4/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
