# $NetBSD: Makefile,v 1.3 2007/04/23 11:29:18 tnn2 Exp $

DISTNAME=		posix_headers-0.2
CATEGORIES=		pkgtools
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.pkgsrc.org/
COMMENT=		POSIX (IEEE 1003.1) compatibility headers

SKIP_AUDIT_PACKAGES=	yes
NO_PKGTOOLS_REQD_CHECK=	yes
NO_CHECKSUM=		yes
NO_MTREE=		yes
NO_CONFIGURE=		yes
NO_BUILD=		yes
NO_EXTRACT=		yes
USE_LANGUAGES=
ONLY_FOR_PLATFORM=	HPUX-11.11-* # add more as needed

PLIST_SRC=		${WRKDIR}/PLIST_SRC

POSIX_HEADERS.HPUX=	sys/select.h stdint.h

do-install:
	for h in ${POSIX_HEADERS.${OPSYS}}; do \
		${INSTALL_DATA} ${FILESDIR}/"$$h" ${PREFIX}/include/"$$h"; \
		echo include/"$$h" >> ${PLIST_SRC}; \
	done

.include "../../mk/bsd.pkg.mk"
