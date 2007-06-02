DISTNAME=		bsdinstaller-20070528
MASTER_SITES=	http://rnrdoctor.sytes.net/~replaced/bsdinstaller/

FILESDIR=			${.CURDIR}/../../wip/bsdinstaller/files

pre-configure:
	${CP} ${FILESDIR}/Config ${WRKDIR}/${DISTNAME}/installer/src/Config