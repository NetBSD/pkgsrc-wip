# $NetBSD: Makefile,v 1.1 2013/05/14 13:39:50 francksys Exp $
#

DISTNAME=	info2man
CATEGORIES=	converters
MASTER_SITES=	http://www.cskk.ezoshosting.com/cs/css/

MAINTAINER=	francksys@free.fr
HOMEPAGE=	http://www.cskk.ezoshosting.com/cs/css/
COMMENT=	Info2man is a wrapper for info2pod to convert info files in man format
LICENSE=	original-bsd # no license

EXTRACT_DIR=   		${WRKDIR}/${DISTNAME}
NO_BUILD=		yes
REPLACE_PERL=   	info2pod
INSTALLATION_DIRS=	bin
INFO2MAN_PM=		Pathname.pm Misc.pm Math.pm Sink.pm IO.pm GNUInfo.pm Source.pm Object.pm DEBUG.pm
PKGNAME=		info2man-0.1


do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/info2man ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/info2pod ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT_DIR} ${DESTDIR}${PERL5_INSTALLVENDORLIB}/cs
	${INSTALL_SCRIPT_DIR} ${DESTDIR}${PERL5_INSTALLVENDORLIB}/cs/GNUInfo/

	cd ${WRKSRC}/cs && for file in ${INFO2MAN_PM}; do \
		${INSTALL_SCRIPT} "$${file}" ${DESTDIR}${PERL5_INSTALLVENDORLIB}/cs; \
	done

	${INSTALL_SCRIPT} ${WRKSRC}/cs/GNUInfo/Node.pm ${DESTDIR}${PERL5_INSTALLVENDORLIB}/cs/GNUInfo


.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
