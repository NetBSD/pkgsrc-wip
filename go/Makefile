# $NetBSD: Makefile,v 1.1 2012/12/30 01:13:18 bsiegert Exp $
#

DISTNAME=	go-1.1pre-20121229
PKGNAME=	${DISTNAME:S/pre-/pre/}
CATEGORIES=	lang
MASTER_SITES=	# manually packaged, on ftp.n.o

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	http://golang.org/
COMMENT=	The Go programming language
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/go
USE_TOOLS+=	bash perl pax
UNLIMIT_RESOURCES= datasize stacksize memorysize

# cgo compiles under TMPDIR
TMPDIR?=	/tmp
BUILDLINK_PASSTHRU_DIRS+= ${TMPDIR}

GOROOT_FINAL=	${PREFIX}/go
INSTALLATION_DIRS= bin

do-build:
	cd ${WRKSRC}/src && ${_ULIMIT_CMD} env GOROOT_FINAL=${GOROOT_FINAL:Q} ${BASH} ./all.bash

do-install:
	cd ${WRKSRC} && rm -f .hgignore .hgtags
	cd ${WRKDIR} && pax -rw go ${DESTDIR}${PREFIX}
.for cmd in go godoc gofmt
	cd ${DESTDIR}${PREFIX}/bin && ln -s ../go/bin/${cmd} ${cmd}
.endfor

.include "../../mk/bsd.pkg.mk"
