# hide the bundled gnus before installing, unhide after deinstalling
#
# $NetBSD: install.sh,v 1.1.1.1 2004/09/14 17:37:24 aolcarton Exp $

EMACS_LISPPREFIX="@EMACS_LISPPREFIX@"
INSTALL_INFO="@INSTALL_INFO@"
INFO_DIR="@INFO_DIR@"

#. /scratch/pkgsrc/mail/t-gnus/files/unit-test.sh

(

RMTEXINFO="${INFO_DIR}/gnus ${INFO_DIR}/message ${INFO_DIR}/emacs-mime"
STASH=${EMACS_LISPPREFIX}/${PKGBASE}_hidden-native-gnus.tar.gz

cd $PKG_PREFIX

case ${STAGE} in
PRE-INSTALL)
	dir=$( ${ECHO} ${EMACS_LISPPREFIX}/../*/lisp/gnus | ${SED} -e 's,[^/]*/\.\./,,g' -e 's,[^/]*/\.\.$,,g' -e 's,[^/]*/\.\. , ,g' )
	set -- $dir
	while [ x$1 != x ]; do
		if [ ! -d $1 ]; then
			break;
		fi
		shift
	done
	if [ x$1 = x -a "x$dir" != x ]; then
		file=""
		for t in ${RMTEXINFO}; do
			for ifile in $t ${t}-[0-9] ${t}-[0-9][0-9]; do
				if [ -f $ifile ]; then
					file="$file $ifile"
				fi
			done
		done
		for f in ${RMTEXINFO}; do
			${INSTALL_INFO} --delete --info-dir=${PKG_PREFIX}/${INFO_DIR} \
		   ${PKG_PREFIX}/${f} 1>/dev/null 2>&1
		done
		_nentries="`${GREP} -c '^\*' ${PKG_PREFIX}/${INFO_DIR}/dir 2>/dev/null`"
		if [ x"${_nentries}" != x -a "${_nentries}" -le 1 ]; then
			${RM} ${PKG_PREFIX}/${INFO_DIR}/dir
		fi
		${GTAR} czf ${STASH} $dir $file
		if [ $? -eq 0 -a -f ${STASH} ]; then
			set -- $dir
			while [ x$1 != x ]; do
				${RM} $1/*
				shift
			done
			${RM} $file
			${RMDIR} $dir
		fi
	fi
	;;
POST-DEINSTALL)
	${GTAR} xBpzf ${STASH} && ${RM} ${STASH}
	for f in ${RMTEXINFO}; do
		${INSTALL_INFO} --delete --info-dir=${PKG_PREFIX}/${INFO_DIR} \
		   ${PKG_PREFIX}/${f} 1>/dev/null 2>&1
		${INSTALL_INFO} --info-dir=${PKG_PREFIX}/${INFO_DIR} \
		   ${PKG_PREFIX}/${f}
	done
	;;
esac

)
