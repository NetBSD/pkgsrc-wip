# $NetBSD: Makefile,v 1.2 2009/06/18 00:00:43 jihbed Exp $
#

DISTNAME=	s3funnel-0.5.2
CATEGORIES=	devel python
MASTER_SITES=	http://s3funnel.googlecode.com/files/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://code.google.com/p/s3funnel/
COMMENT=	Multithreaded tool for performing operations on Amazon S3

DEPENDS+=	${PYPKGPREFIX}-workerpool-[0-9]*:../../wip/py-workerpool

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../net/py-boto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
