# $NetBSD: Makefile,v 1.1.1.1 2004/02/23 20:36:32 tomhensel Exp $

DISTNAME=	pyzor-0.4.0
CATEGORIES=	mail
MASTER_SITES=	$(MASTER_SITE_SOURCEFORGE:=pyzor/)
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tom@replic8.net
HOMEPAGE=	http://pyzor.sourceforge.net/
COMMENT=	Collaborative, networked system to detect and block spam

# Pyzord depends on py-gdbm
#DEPENDS+=	py23-gdbm>=0nb1:../../databases/py-gdbm

#.include "../../mk/bsd.prefs.mk"

# Pyzord depends on python with threads
#PYTHON_VERSIONS_ACCEPTED=	23pth
PYTHON_VERSIONS_ACCEPTED=	23 23pth

post-patch:
	@${MV} ${WRKSRC}/scripts/pyzor ${WRKSRC}/scripts/pyzor.tmp
	@${SED} "s,/usr/bin/python2,${PYTHONBIN}," ${WRKSRC}/scripts/pyzor.tmp	\
		> ${WRKSRC}/scripts/pyzor
	@${MV} ${WRKSRC}/scripts/pyzord ${WRKSRC}/scripts/pyzord.tmp
	@${SED} "s,/usr/bin/python2,${PYTHONBIN}," ${WRKSRC}/scripts/pyzord.tmp	\
		> ${WRKSRC}/scripts/pyzord

do-build:
	(cd ${WRKSRC}; ${PYTHONBIN} ${WRKSRC}/setup.py build)

do-install:
	(cd ${WRKSRC}; ${PYTHONBIN} ${WRKSRC}/setup.py install)

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
