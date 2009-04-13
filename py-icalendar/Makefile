# $NetBSD: Makefile,v 1.3 2009/04/13 22:46:48 jihbed Exp $
#

DISTNAME=	iCalendar-1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/Calendar/calendar/}
CATEGORIES=	time python
MASTER_SITES=	http://codespeak.net/icalendar/
EXTRACT_SUFX=	.tgz

MAINTAINER=	mj@turner.org.za
HOMEPAGE=	http://codespeak.net/icalendar/
COMMENT=	Python parser/generator for iCalendar files, as per RFC2445

PKG_DESTDIR_SUPPORT=	user-destdir

PY_PATCHPLIST=	yes

DOCDIR=	${PREFIX}/share/doc/${PKGNAME}
# Install documentation manually
post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DESTDIR}${DOCDIR}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
