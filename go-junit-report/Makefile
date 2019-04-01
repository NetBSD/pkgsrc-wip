# $NetBSD$

GITHUB_PROJECT=	go-junit-report
GITHUB_TAG= 	af01ea7f8024089b458d804d5cdf190f962a9a0c
#DISTNAME=		go-junit-report	
DISTNAME= 		${GITHUB_PROJECT}-${GITHUB_TAG}

CATEGORIES=	wip
MASTER_SITES=	${MASTER_SITE_GITHUB:=jstemmer/}
EXTRACT_SUFX=	.zip
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	INSERT_YOUR_MAIL_ADDRESS_HERE
HOMEPAGE=	https://github.com/jstemmer/go-junit-report/
COMMENT=	TODO: Short description of the package
#LICENSE=	# TODO: (see mk/license.mk)

USE_LANGUAGES = go

DEPENDS+= go>=1.1:../../lang/go

WRKSRC=		${WRKDIR}/myaasss



# url2pkg-marker (please do not remove this line.)
.include "../../mk/bsd.pkg.mk"
.include "../../lang/go/go-package.mk"

