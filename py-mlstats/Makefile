# $NetBSD: Makefile,v 1.1.1.1 2011/04/27 22:34:10 jihbed Exp $
#

DISTNAME=	mlstats-0.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	https://forge.morfeo-project.org/frs/download.php/777/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://forge.morfeo-project.org/projects/libresoft-tools
COMMENT=	Mailing lists analysis tool. Part of libresoft-tool
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-mysqldb-[0-9]*:../../databases/py-mysqldb

PKG_DESTDIR_SUPPORT=	user-destdir

# Force using "curl" for fetching the distribution file. It is only available
# over HTTPS and "curl" is the only fetch program which always supports HTTPS.
FETCH_USING=	curl

PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}
PYDISTUTILSPKG=	yes

post-extract:
	${MV} ${WRKSRC}/mlstats ${WRKSRC}/mlstats${PYVERSSUFFIX}


.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
