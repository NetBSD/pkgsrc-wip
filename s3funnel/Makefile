# $NetBSD: Makefile,v 1.5 2012/10/07 16:22:53 asau Exp $
#

DISTNAME=	s3funnel-0.5.2
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	http://s3funnel.googlecode.com/files/

MAINTAINER=	pkgsrc-users@netbsd.org
HOMEPAGE=	http://code.google.com/p/s3funnel/
COMMENT=	Multithreaded tool for performing operations on Amazon S3

DEPENDS+=       ${PYPKGPREFIX}-boto>=1.9:../../net/py-boto
DEPENDS+=	${PYPKGPREFIX}-workerpool-[0-9]*:../../wip/py-workerpool

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
