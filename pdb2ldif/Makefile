# $NetBSD: Makefile,v 1.4 2004/05/02 21:43:17 blef Exp $
#

DISTNAME=	pdb2ldif-1.1
CATEGORIES=	converters
MASTER_SITES=	http://www.uslinux.net/software/packages/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.uslinux.net/software/pkginfo.php?pkg=pdb2ldif
COMMENT=	Converts Palm Address Book PDB files into an LDAP-usable LDIF file

DEPENDS+=	p5-Palm>=1.3.0:../../devel/p5-Palm

NO_BUILD=	YES
USE_BUILDLINK3=	YES

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pdb2ldif ${PREFIX}/bin/pdb2ldif

.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
