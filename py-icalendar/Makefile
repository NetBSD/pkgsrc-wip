# $NetBSD: Makefile,v 1.2 2008/05/22 15:38:47 tnn2 Exp $
#

DISTNAME=	iCalendar-1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/Calendar/calendar/}
CATEGORIES=	time python
MASTER_SITES=	http://codespeak.net/icalendar/
EXTRACT_SUFX=	.tgz

MAINTAINER=	mj@turner.org.za
HOMEPAGE=	http://codespeak.net/icalendar/
COMMENT=	Python parser/generator for iCalendar files, as per RFC2445

PYDISTUTILSPKG=	yes
PY_PATCHPLIST=	yes

# Install documentation manually
post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${PREFIX}/share/doc/${PKGBASE}

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
