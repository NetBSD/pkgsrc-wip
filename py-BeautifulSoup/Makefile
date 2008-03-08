# $NetBSD: Makefile,v 1.3 2008/03/08 18:15:24 dhowland Exp $
#

DISTNAME=		BeautifulSoup-3.0.5
PKGNAME=                ${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		textproc
MASTER_SITES=		http://www.crummy.com/software/BeautifulSoup/download/ \
			http://gentoo.osuosl.org/distfiles/ \
			http://gd.tuwien.ac.at/opsys/linux/gentoo/distfiles/

MAINTAINER=		dhowland@users.sourceforge.net
HOMEPAGE=		http://www.crummy.com/software/BeautifulSoup/
COMMENT=		HTML and XML parser for Python

PYDISTUTILSPKG=			yes
PYTHON_VERSIONS_ACCEPTED=       25 24 23

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
