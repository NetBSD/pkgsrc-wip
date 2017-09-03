# $NetBSD: Makefile,v 1.13 2015/02/17 08:12:29 thomasklausner Exp $

PKGNAME=	${PYPKGPREFIX}-gettext-tools-${PY_DISTVERSION}
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.python.org/topics/database/
COMMENT=	Python tools for development of I18N Python apps

NO_BUILD=	yes
AUTO_MKDIRS=	yes

EXTRACT_ELEMENTS=		${PYSUBDIR}/Tools/i18n/*

REPLACE_PYTHON=		Tools/i18n/msgfmt.py Tools/i18n/pygettext.py
PLIST_SUBST+=		PYVERSSUFFIX=${PYVERSSUFFIX}

do-patch:
	@echo "Patches ignored"

do-install:
	for a in ${REPLACE_PYTHON}; do \
		${INSTALL_SCRIPT} ${WRKSRC}/$$a ${DESTDIR}${PREFIX}/bin/`${BASENAME} $$a`-${PYVERSSUFFIX}; \
	done

.include "../../lang/python/application.mk"
.include "../../lang/python/srcdist.mk"
.include "../../mk/bsd.pkg.mk"
