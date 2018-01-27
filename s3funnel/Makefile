# $NetBSD: Makefile,v 1.8 2015/04/09 11:42:56 thomasklausner Exp $

DISTNAME=	s3funnel-0.5.2
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	http://s3funnel.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/s3funnel/
COMMENT=	Multithreaded tool for performing operations on Amazon S3

DEPENDS+=	${PYPKGPREFIX}-boto>=1.9:../../net/py-boto
DEPENDS+=	${PYPKGPREFIX}-workerpool-[0-9]*:../../wip/py-workerpool

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # not yet ported as of 0.5.2

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
