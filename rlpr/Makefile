# $NetBSD: Makefile,v 1.3 2004/05/15 14:07:29 kheinz Exp $
# FreeBSD Id: ports/print/rlpr/Makefile,v 1.12 2003/03/07 06:09:06 ade Exp

DISTNAME=	rlpr-2.04
CATEGORIES=	print net
MASTER_SITES=	ftp://www.truffula.com/pub/

MAINTAINER=	pkg@pop.707.to
HOMEPAGE=	http://truffula.com/rlpr/
COMMENT=	Send print jobs to lpd servers anywhere on a network

GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--disable-nls --without-catgets

INSTALL_TARGET=	install install-setuid

post-patch:
	# Replacing references to /etc/rlprrc to ${PREFIX}/etc/rlprrc
	@for f in `${GREP} -l /etc/rlprrc ${WRKSRC}/man/*.[0-9n]`; do \
		if ${TEST} -r $$f.orig; then continue; fi; \
		${MV} $$f $$f.orig ; \
		${SED} s%/etc/rlprrc%${PREFIX}/etc/rlprrc%g < $$f.orig > \
			$$f ; \
	done
	@${MV} ${WRKSRC}/src/rlprrc.h ${WRKSRC}/src/rlprrc.h.orig
	@${SED} s%/etc%${PREFIX}/etc%g < ${WRKSRC}/src/rlprrc.h.orig \
		> ${WRKSRC}/src/rlprrc.h
	@${MV} ${WRKSRC}/man/rlpr.1 ${WRKSRC}/man/rlpr.1.orig2
	@${SED} 's%\\fB\/etc\\fP%\\fB${PREFIX}/etc\\fP%' \
		< ${WRKSRC}/man/rlpr.1.orig2 > ${WRKSRC}/man/rlpr.1

.include "../../mk/bsd.pkg.mk"
