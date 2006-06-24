# $NetBSD: Makefile,v 1.1.1.1 2006/06/24 01:47:20 achemze Exp $
#

DISTNAME=		hellanzb-0.9
CATEGORIES=		news
MASTER_SITES=		http://www.hellanzb.com/distfiles/
DISTFILES=		${DISTNAME}.tar.gz

MAINTAINER=		silicon@kalifornia.com
HOMEPAGE=		http://www.hellanzb.com/
COMMENT=		Command line nntp file grabber

DEPENDS+=       	${PYPKGPREFIX}-twisted-1.3.*:../../net/py-twisted
DEPENDS+=       	par2>=0.4:../../archivers/par2
DEPENDS+=       	unrar>=3.5.4:../../archivers/unrar

PYDISTUTILSPKG= yes
PYTHON_VERSIONS_ACCEPTED=       24 23

.include "../../textproc/py-xml/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
