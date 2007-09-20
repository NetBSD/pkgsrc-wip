# $NetBSD: Makefile,v 1.5 2007/09/20 22:55:20 thomasklausner Exp $
#

DISTNAME=		hellanzb-0.12
CATEGORIES=		news
MASTER_SITES=		http://www.hellanzb.com/distfiles/ 
DISTFILES=		${DISTNAME}.tar.gz

MAINTAINER=		silicon@kalifornia.com
HOMEPAGE=		http://www.hellanzb.com:8080/trac
COMMENT=		Command line nntp file grabber

DEPENDS+=	${PYPKGPREFIX}-twisted>=1.3:../../net/py-twisted
DEPENDS+=	par2>=0.4:../../archivers/par2
DEPENDS+=	unrar>=3.5.4:../../archivers/unrar

PYDISTUTILSPKG= yes
PYTHON_VERSIONS_ACCEPTED=	24 23

.include "../../textproc/py-xml/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
