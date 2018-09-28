# $NetBSD$

DISTNAME=	minio-${GITHUB_TAG}
PKGNAME=	minio-20180912184956
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=minio/}
GITHUB_PROJECT=	minio
GITHUB_TAG=	RELEASE.2018-09-12T18-49-56Z

MAINTAINER=	cfkoch@edgebsd.org
HOMEPAGE=	https://minio.io
COMMENT=	High performance distributed object storage server
LICENSE=	apache-2.0

EXTRACT_USING=	gtar

GO_DIST_BASE=	${DISTNAME}
GO_SRCPATH=	github.com/minio/minio

# XXX Only because I personally don't see the point installing all, like,
# 3000+ files of this package's source... all of the vendor/'d stuff, you
# know what I mean?
do-install:
	${INSTALL_PROGRAM_DIR} ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKDIR}/bin/minio ${DESTDIR}${PREFIX}/bin

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
