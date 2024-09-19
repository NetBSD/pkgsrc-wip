# $NetBSD$

DISTNAME=       commisery-0.5.0
PKGNAME=        ${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=     devel sysutils
MASTER_SITES=   ${MASTER_SITE_PYPI:=c/commisery/}

MAINTAINER=	root@zta.lk
HOMEPAGE=	https://github.com/tomtom-international/commisery/
COMMENT=	Check whether given commit messages adhere to Conventional Commits.
LICENSE=	apache-2.0

post-install:
	cd ${DESTDIR}${PREFIX}/bin && for b in commisery-verify-github-pullrequest commisery-verify-msg; \
	  do ${MV} $$b $$b-${PYVERSSUFFIX}; \
	done

DEPENDS+=	${PYPKGPREFIX}-stemming>=1<2:../../wip/py-stemming
DEPENDS+=	${PYPKGPREFIX}-regex:../../textproc/py-regex

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
