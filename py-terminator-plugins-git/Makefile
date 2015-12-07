# $NetBSD$

PKGNAME=	${PYPKGPREFIX}-terminator-plugins-0
CATEGORIES=	x11

GIT_REPOSITORIES=	TP
GIT_REPO.TP=		https://github.com/camillo/TerminatorPlugins.git

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${MASTER_SITE_GITHUB:=camillo/TerminatorPlugins/}
COMMENT=	Set of plugins for terminator
LICENSE=	public-domain

WRKSRC=		${WRKDIR}/TP

NO_BUILD=	yes
PY_PATCHPLIST=	yes

TERMINATORLIB_PLUGINS=	${PREFIX}/${PYSITELIB}/terminatorlib/plugins/

do-install:
	${RUN} ${INSTALL_DATA_DIR} ${DESTDIR}${TERMINATORLIB_PLUGINS}
.for plugin in LayoutManager.py TerminalExporter.py
	${RUN} cd ${WRKSRC} && \
		${INSTALL_DATA} plugins/${plugin} ${DESTDIR}${TERMINATORLIB_PLUGINS}
.endfor

.include "../../wip/mk/git-package.mk"
.include "../../lang/python/pyversion.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
