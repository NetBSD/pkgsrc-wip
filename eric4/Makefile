# $NetBSD: Makefile,v 1.5 2010/04/10 23:59:04 helgoman Exp $
#

VERS=			4.4.3
DISTNAME=		eric4-${VERS}
PKGREVISION=	1
CATEGORIES=		devel
MASTER_SITES=	http://downloads.sourceforge.net/project/eric-ide/eric4/stable/${VERS}/

MAINTAINER=		helgoman@users.sourceforge.net
HOMEPAGE=		http://eric-ide.python-projects.org/index.html
COMMENT=		Python - IDE
LICENSE=		gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir
NO_BUILD=				yes


PY_PATCHPLIST=			yes

CONFIGURE_ARGS+=		-b ${DESTDIR}${PREFIX}/bin
CONFIGURE_ARGS+=		-d ${DESTDIR}${PREFIX}/${PYSITELIB}
CONFIGURE_ARGS+=		-a ${DESTDIR}${PREFIX}/qt4/qsci/api


do-install:
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${PYTHONBIN} install.py ${CONFIGURE_ARGS})

.include "options.mk"
.include "../../lang/python/extension.mk"
.include "../../x11/py-qt4/buildlink3.mk"
.include "../../wip/qt4-qscintilla/buildlink3.mk"
.include "../../wip/py-qt4-qscintilla/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
