# $NetBSD: Makefile,v 1.100 2021/04/21 11:41:24 adam Exp $
#

DISTNAME=	Frama-C-snapshot-20.0
PKGNAME=	${DISTNAME:S/-snapshot//:tl}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=Frama-C/}

MAINTAINER=	tonio@NetBSD.org
HOMEPAGE=	https://github.com/Frama-C/Frama-C-snapshot/
COMMENT=	Extensible platform dedicated to source-code analysis of C software
LICENSE=	gnu-lgpl-v2
# review license directory
# CDDL-1.0  LGPLv2  LGPLv2.1  Q_MODIFIED_LICENSE

USE_TOOLS+=	gmake autoconf bash
GNU_CONFIGURE=	yes

OCAML_USE_FINDLIB=	yes

REPLACE_BASH+=		bin/frama-c-script
REPLACE_BASH+=		share/analysis-scripts/clone.sh
REPLACE_BASH+=		share/analysis-scripts/cmd-dep.sh
REPLACE_BASH+=		share/analysis-scripts/concat-csv.sh
REPLACE_BASH+=		share/analysis-scripts/parse-coverage.sh

REPLACE_PERL+=		share/analysis-scripts/flamegraph.pl

REPLACE_PYTHON+=	share/analysis-scripts/find_fun.py
REPLACE_PYTHON+=	share/analysis-scripts/list_files.py
REPLACE_PYTHON+=	share/analysis-scripts/make_template.py
REPLACE_PYTHON+=	share/analysis-scripts/make_wrapper.py
REPLACE_PYTHON+=	share/analysis-scripts/summary.py

.include "options.mk"

post-install:
#	${CHMOD} -x ${DESTDIR}${PREFIX}/lib/frama-c/*.cm*
#	${CHMOD} -x ${DESTDIR}${PREFIX}/lib/frama-c/plugins/*/*
#	${CHMOD} -x ${DESTDIR}${PREFIX}/lib/frama-c/plugins/*
#	${CHMOD} -x ${DESTDIR}${PREFIX}/lib/frama-c/theme/*
	find ${DESTDIR}${PREFIX}/share/frama-c -type f -exec chmod a-x {} +
	find ${DESTDIR}${PREFIX}/lib/frama-c   -type f -exec chmod a-x {} +
	find ${DESTDIR}${PREFIX}/man           -type f -exec chmod a-x {} +
	find ${DESTDIR}${PREFIX}/lib           -type f -exec chmod a-x {} +


# WARNING: you must build ocamlgraph with ocaml-lablgtk support
# (not the default) or the build fails with missing module "Dgraph".

.include "../../devel/ocamlgraph/buildlink3.mk"
.include "../../math/ocaml-zarith/buildlink3.mk"
.include "../../devel/ocaml-yojson/buildlink3.mk"
.include "../../x11/gtksourceview3/buildlink3.mk"
.include "../../graphics/cairo-gobject/buildlink3.mk"
.include "../../lang/python/application.mk"

.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
