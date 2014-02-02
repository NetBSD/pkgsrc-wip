# $NetBSD: Makefile,v 1.2 2014/02/02 13:32:17 bsiegert Exp $
#

DISTNAME=		go.text
CATEGORIES=		devel

MAINTAINER=		bsiegert@NetBSD.org
HOMEPAGE=		http://golang.org/
COMMENT=		Supplementary text processing libraries for Go
LICENSE=		modified-bsd

GO_SRCPATH=		code.google.com/p/go.text
WRKSRC=			${WRKDIR}/src/${GO_SRCPATH}

CHECKOUT_DATE=		2014-01-16
HG_REPOSITORIES=	${DISTNAME}
HG_REPO.${DISTNAME}=	https://${GO_SRCPATH}

BUILD_DEPENDS+=		go>=1.2:../../lang/go

MAKE_JOBS_SAFE=		no
INSTALLATION_DIRS=	bin go/src/pkg

post-extract:
	${MKDIR} ${WRKSRC}
	${RM} -fr ${WRKDIR}/`basename ${GO_SRCPATH}`/.hg
	${MV} ${WRKDIR}/`basename ${GO_SRCPATH}` `dirname ${WRKSRC}`

do-build:
	env GOPATH=${WRKDIR} go install -v ${GO_SRCPATH}/...

do-install:
	cd ${WRKDIR} && ${PAX} -rw bin ${DESTDIR}/${PREFIX}
	cd ${WRKDIR}/src && ${PAX} -rw * ${DESTDIR}/${PREFIX}/go/src/pkg

.include "../../wip/mk/hg-package.mk"
.include "../../mk/bsd.pkg.mk"
