# $NetBSD: Makefile,v 1.2 2003/05/02 07:23:15 drue Exp $

DISTNAME=	sigrot_${DIST_VERS}-1
PKGNAME=	sigrot-${DIST_VERS}
WRKSRC=		${WRKDIR}/${PKGNAME}
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.debian.org/debian/pool/main/s/sigrot/ \
		ftp://ftp.de.debian.org/debian/pool/main/s/sigrot/
# you can list all Debian mirros here ;-)

DIST_VERS=	1.2
MAINTAINER=	drue@users.sourceforge.net
HOMEPAGE=	http://packages.debian.org/stable/mail/sigrot.html
COMMENT=	Signature file rotation program

SRDOCS= 	${PREFIX}/share/doc/sigrot
SREXAM= 	${PREFIX}/share/sigrot
USE_GMAKE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sigrot ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/sigrot.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${SRDOCS}
	${INSTALL_DATA} ${WRKSRC}/copyright ${SRDOCS}/COPYRIGHT
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${SRDOCS}/INSTALL
	${INSTALL_DATA_DIR} ${SREXAM}
	${INSTALL_DATA} ${WRKSRC}/examples/prefix ${SREXAM}/prefix
	${INSTALL_DATA} ${WRKSRC}/examples/sig_archive ${SREXAM}/sig_archive
	${INSTALL_DATA} ${WRKSRC}/examples/suffix ${SREXAM}/suffix

.include "../../mk/bsd.pkg.mk"
