# $NetBSD: go-package.mk,v 1.1 2014/02/02 14:01:59 bsiegert Exp $
#
# This file implements common logic for compiling Go programs in pkgsrc.
# The compiled Go code is tied to a specific compiler version, and the
# compilation is fast. So the plan is:
#
# 1. Compile everything.
# 2. Install binaries into bin/.
# 3. Install the source code into the Go tree.

# Packages using this should set GO_SRCPATH to the path that could
# be used with "go get" (usually the URL without the leading protocol).

WRKSRC=			${WRKDIR}/src/${GO_SRCPATH}

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
