# $NetBSD: Makefile,v 1.1.1.1 2004/01/26 18:32:53 schnoebe Exp $
#

DISTNAME=       interchange-4.8.7
PKGNAME=        ${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	http://ftp.icdevgroup.org/interchange/4.8/tar/

MAINTAINER=	eric@cirr.com
HOMEPAGE=	http://interchange.redhat.com/
COMMENT=	Catalog application for web use (more than a web shopping cart.)

DEINSTALL_FILE=		${WRKDIR}/DEINSTALL
INSTALL_FILE=		${WRKDIR}/INSTALL
# MESSAGE=		${WRKDIR}/MESSAGE
MESSAGE_SUBST+= 	ICUSER=${INTERCHANGE_USER}	\
			ICGROUP=${INTERCHANGE_GROUP}	\
			ICDIR=${INTERCHANGE_DIR}

DEPENDS+=	p5-DBI:../../databases/p5-DBI
DEPENDS+=	p5-SQL-Statement:../../databases/p5-SQL-Statement
DEPENDS+=	p5-Safe-Hole>=0.07:../../devel/p5-Safe-Hole
DEPENDS+=	p5-MIME-Base64>=2.11:../../converters/p5-MIME-Base64
DEPENDS+=	p5-Storable>=1.0.6:../../devel/p5-Storable
DEPENDS+=	p5-URI>=1.09:../../www/p5-URI
DEPENDS+=	p5-HTML-Parser>=3.13:../../www/p5-HTML-Parser
DEPENDS+=	p5-HTML-Tagset>=3.03:../../www/p5-HTML-Tagset
DEPENDS+=	p5-libwww>=5.48:../../www/p5-libwww
DEPENDS+=	p5-Business-UPS>=1.0.6:../../misc/p5-Business-UPS
#	Interchange uses the following if they are available
# DEPENDS+=	p5-Term-ReadKey>=2.14:../../devel/p5-Term-ReadKey

#	This could also depend upon a web server (apache), but 
#	I'm not sure how reasonable _that_ is, a the web server 
#	could be on another machine.  Additionally, it could also
#	depend upon a database, but which one (postgresql or mysql or ...)

# 	The huge number of depends are to keep the installation program 
#	(Makefile.PL, which is called as part of the install) from 
#	having the CPAN module install a large number of modules
#	outside the control of pkg_*

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.pkg.install.mk"

USE_PERL5=	# defined

# Interchange User name (user id owning/running the daemon)
INTERCHANGE_USER?=interchg
# the install perl program _assumes_ the group name is the same
# as the username (yes, Virgina, apparently all the world _is_ RH Linux)
INTERCHANGE_GROUP?=${INTERCHANGE_USER}

# installation directory for interchange
INTERCHANGE_DIR?=${PREFIX}/interchange

PKG_USERS=${INTERCHANGE_USER}:${INTERCHANGE_GROUP}:Interchange\\ Catalog\\ User:${INTECHANGE_DIR}

PERL5_PACKLIST=		${INTERCHANGE_DIR}/auto/Interchange/.packlist
PLIST_SRC=	PLIST_SRC

do-configure:
	@cd ${WRKSRC}; \
	${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL \
		rpmbuilddir=${WRKSRC} \
		INTERCHANGE_USER=${INTERCHANGE_USER} \
		PREFIX=${INTERCHANGE_DIR} \
		INSTALLMAN1DIR=${PREFIX}/man/man1 \
		INSTALLMAN3DIR=${PREFIX}/man/man8 \
		INSTALLBIN=${PREFIX}/bin \
		link_file=/var/run/interchange/socket \
		force=1

post-build:
	${SED}	-e "s|@PREFIX@|${PREFIX}|g" \
		-e 's|@ICUSER@|${INTERCHANGE_USER}|g' \
		-e 's|@ICGROUP@|${INTERCHANGE_GROUP}|g' \
		< ${FILESDIR}/interchange.sh > ${WRKDIR}/interchange.sh

pre-install:
	#${SED}	-e 's|@ICUSER@|${INTERCHANGE_USER}|g' \
	#	-e 's|@ICGROUP@|${INTERCHANGE_GROUP}|g' \
	#	-e 's|@ICDIR@|${INTERCHANGE_DIR}|g' \
	#	-e 's|@PREFIX@|${PREFIX}|g' \
	#	< ${PKGDIR}/MESSAGE > ${MESSAGE}
	${SED}	-e 's|@ICUSER@|${INTERCHANGE_USER}|g' \
		-e 's|@ICGROUP@|${INTERCHANGE_GROUP}|g' \
		< ${PKGDIR}/DEINSTALL > ${DEINSTALL_FILE}
	${SED}	-e 's|@ICUSER@|${INTERCHANGE_USER}|g' \
		-e 's|@ICGROUP@|${INTERCHANGE_GROUP}|g' \
		-e 's|@ICDIR@|${INTERCHANGE_DIR}|g' \
		-e 's|@ADDUSER@|${ADDUSER}|g' \
		-e 's|@ADDGROUP@|${ADDGROUP}|g' \
		-e 's|@CHGRP@|${CHGRP}|g' \
		-e 's|@ID@|${ID}|g' \
		-e 's|@TOUCH@|${TOUCH}|g' \
		-e 's|@RM@|${RM}|g' \
		< ${PKGDIR}/INSTALL > ${INSTALL_FILE}
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} PRE-INSTALL

# Create symbolic links to allow most of the included commands to
# operate correctly, while allowing NetBSD to mount this filesystem
# read-only (if desired.)
#
#   The symlinks are for the (error and access) log, 
#   the daemon configuration file,
#   the makecat (make catalog) configuration file and the daemon
#   communication unix domain socket
#
# Change the ownership on the tree to be the interchange user, mostly
# because that is what the RPM spec file does
#
# Install the daemon start up script in ${PREFIX}/etc/rc.d
#
# Install the interchange PDF documentation in ${PREFIX}/share/doc
# (interchange documentation is now in a seperate tarball)
#	for i in ${WRKDIR}/${DISTNAME}/pdf/*.pdf ; do \
#	    ${INSTALL_DATA} $$i ${PREFIX}/share/doc/interchange ;\
#	done
#
# (finally) Execute the post-install phase of the installation
#  (create/copy interchange.cfg, makecat.cfg)
post-install:
	cd ${INTERCHANGE_DIR}; ${LN} -s ../etc/interchange.cfg .
	cd ${INTERCHANGE_DIR}; ${RM} -f error.log; \
		${LN} -s /var/log/interchange.log error.log
	cd ${INTERCHANGE_DIR}/etc; ${RM} -f access_log; \
		${LN} -s /var/log/interchange/access_log access_log
	cd ${INTERCHANGE_DIR}/etc; ${LN} -s /var/run/interchange/socket .
	cd ${INTERCHANGE_DIR}/etc; ${LN} -s ../../etc/makecat.cfg .
	${CHOWN} -R ${INTERCHANGE_USER} ${INTERCHANGE_DIR}
	${INSTALL_SCRIPT} ${WRKDIR}/interchange.sh \
					${PREFIX}/etc/rc.d/interchange
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/interchange
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"
