# $NetBSD: Makefile,v 1.3 2005/01/02 01:16:04 aolcarton Exp $

DISTNAME=	t-gnus-6.17.2.00
CATEGORIES=	mail
FETCH_CMD=	${FILESDIR}/fetch.sh

MAINTAINER=	carton@Ivy.NET
HOMEPAGE=	http://www.gnus.org/
COMMENT=	Gnus is a flexible message reader running under GNU Emacs

DEPENDS+=	semi>=1.14.6:../../devel/semi

WRKSRC=		${WRKDIR}/gnus

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-lispdir=${EMACS_LISPPREFIX}/gnus
CONFIGURE_ARGS+=	--with-etcdir=${PREFIX}/share/gnus

BUILD_TARGET=		all-ja
INSTALL_TARGET=		install-ja

USE_MAKEINFO=		YES
INFO_FILES=		t-gnus t-message t-emacs-mime t-sieve t-gnus-ja t-message-ja

# last template is ${_FOOTER_TMPL} which is just 'exit 0'.  but conveniently 
# the pkgsrc graybeards have said INSTALL_SRC?=${INSTALL_TEMPLATES}.  insert 
# our INSTALL/DEINSTALL script as second-to-last.
INSTALL_SRC=		${INSTALL_TEMPLATES:[1..-2]} ${FILESDIR}/install.sh ${INSTALL_TEMPLATES:[-1]}
DEINSTALL_SRC=		${DEINSTALL_TEMPLATES:[1..-2]} ${FILESDIR}/install.sh ${DEINSTALL_TEMPLATES:[-1]}
FILES_SUBST+=		EMACS_LISPPREFIX=${EMACS_LISPPREFIX:C|^${PREFIX}/||}

#pre-configure:
#	cd ${WRKSRC} && ${AUTORECONF} --force

.include "../../mk/emacs.mk"
.include "../../mk/bsd.pkg.mk"
