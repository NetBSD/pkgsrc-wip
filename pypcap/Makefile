# $NetBSD: Makefile,v 1.3 2010/02/14 11:20:29 pettai Exp $
#

DISTNAME=	pypcap-1.1
PKGNAME=	${PYPKGPREFIX}-pypcap-1.1
CATEGORIES=	net
MASTER_SITES=	http://pypcap.googlecode.com/files/

MAINTAINER=	pettai@nordu.net
HOMEPAGE=	http://code.google.com/p/pypcap/
COMMENT=	Simplified object-oriented python module for libpcap
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

SUBST_CLASSES+=         python
SUBST_FILES.python=     Makefile
SUBST_SED.python+=      -e 's,@PYTHON@,${PYTHONBIN},g'
SUBST_STAGE.python=     post-patch
SUBST_CLASSES+=         prefix
SUBST_FILES.prefix=     Makefile
SUBST_SED.prefix=       -e "s|@PREFIX@|${PREFIX}|g"
SUBST_STAGE.prefix=     post-patch

PYDISTUTILSPKG= yes

FILES_SUBST+=   PYTHONBIN=${PYTHONBIN:Q}

do-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
	${PYTHONBIN} setup.py config --with-pcap=${PREFIX}

.include "../../net/libpcap/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
